import tkinter as tk
import serial

# Configura la conexión serial
# Asegúrate de especificar el puerto correcto y la velocidad de baudios correcta
ser = serial.Serial('COM4', 9600)  # Cambia 'COM3' por el puerto correcto

def encender():
    ser.write(b'1')  # Envía '1' por el puerto serial para encender el circuito

def apagar():
    ser.write(b'0')  # Envía '0' por el puerto serial para apagar el circuito

# Crea la ventana principal
root = tk.Tk()
root.title("Control de Circuito")

# Crea los botones para encender y apagar el circuito
btn_encender = tk.Button(root, text="Encender", command=encender)
btn_encender.pack()

btn_apagar = tk.Button(root, text="Apagar", command=apagar)
btn_apagar.pack()

# Función para cerrar el puerto serial antes de cerrar la aplicación
def cerrar_serial():
    ser.close()
    root.destroy()

# Asigna la función de cerrar_serial() para ejecutarse cuando se cierre la ventana
root.protocol("WM_DELETE_WINDOW", cerrar_serial)

# Inicia el bucle principal de la interfaz gráfica
root.mainloop()
