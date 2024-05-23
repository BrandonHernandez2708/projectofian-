import serial
import time
import tkinter as tk
from threading import Thread
import mysql.connector
from datetime import datetime

class TrafficLightGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Semáforo")

       
        self.canvas = tk.Canvas(root, width=200, height=400)
        self.canvas.pack()

        
        self.led_rojo = self.canvas.create_oval(50, 50, 150, 150, fill='grey')
        self.led_amarillo = self.canvas.create_oval(50, 150, 150, 250, fill='grey')
        self.led_verde = self.canvas.create_oval(50, 250, 150, 350, fill='grey')

        # Configurar la conexión serial
        self.arduino_port = "COM4"  # Reemplaza con el puerto adecuado
        self.baud_rate = 9600
        self.ser = serial.Serial(self.arduino_port, self.baud_rate, timeout=1)
        time.sleep(2)  # Espera para asegurar que la conexión se haya establecido

       
        self.read_thread = Thread(target=self.read_serial)
        self.read_thread.daemon = True
        self.read_thread.start()

        self.update_lights()

        # Capturar evento de cierre de la ventana
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)

        # Configurar la conexión a la base de datos
        self.db_conn = mysql.connector.connect(user='root', password="Angry2708",
                                               host="localhost",
                                               database="ledcontrol",
                                               port="3306")
        self.cursor = self.db_conn.cursor()

    def read_serial(self):
        while True:
            if self.ser.in_waiting > 0:
                line = self.ser.readline().decode('utf-8').rstrip()
                print(line)
                self.process_line(line)

    def process_line(self, line):
        current_time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        if "LED Rojo: encendido" in line:
            self.canvas.itemconfig(self.led_rojo, fill='red')
            self.log_event("Rojo", "ON", current_time)
        elif "LED Rojo: Apagado" in line:
            self.canvas.itemconfig(self.led_rojo, fill='grey')
        elif "LED Amarillo: Encendido" in line:
            self.canvas.itemconfig(self.led_amarillo, fill='yellow')
            self.log_event("Amarillo", "ON", current_time)
        elif "LED Amarillo: Apagado" in line:
            self.canvas.itemconfig(self.led_amarillo, fill='grey')
        elif "LED Verde: Encendido" in line:
            self.canvas.itemconfig(self.led_verde, fill='green')
            self.log_event("Verde", "ON", current_time)
        elif "LED Verde: Apagado" in line:
            self.canvas.itemconfig(self.led_verde, fill='grey')

    def log_event(self, led_color, state, timestamp):
        query = "INSERT INTO led_events (led_color, state, timestamp) VALUES (%s, %s, %s)"
        self.cursor.execute(query, (led_color, state, timestamp))
        self.db_conn.commit()

    def update_lights(self):
        self.root.after(100, self.update_lights)  # Actualiza cada 100 ms

    def on_closing(self):
        print("*****Gracias por su visita*****")
        self.ser.close()
        self.cursor.close()
        self.db_conn.close()
        self.root.destroy()

def main():
    root = tk.Tk()
    app = TrafficLightGUI(root)
    root.mainloop()

if __name__ == "__main__":
    main()
