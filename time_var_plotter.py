import serial
import matplotlib.pyplot as plt
import time
import pandas as pd
ser = serial.Serial('COM5', 9600)  # replace with your serial port

### --  factor obtenido de la celda -- ###
factor = 0.5

plt.ion()
fig, ax = plt.subplots()
line, = ax.plot([])
ax.set_ylim(-10, 1023)
ax.set_xlim(0, 100)
ax.set_title('ME4110 - Herramienta celda de carga')
ax.set_xlabel('Tiempo (s)')
ax.set_ylabel('Carga [N]')
ax.grid()


x_data = []
y_data = []

start_time = time.time()
while True:
    try:
        value_celda = int(ser.readline().decode().strip())
        value_norm = value_celda*factor
        x_data.append(time.time() - start_time)
        y_data.append(value_norm)
        line.set_data(x_data, y_data)
        ax.set_xlim(max(0, x_data[-1] - 100), x_data[-1])
        fig.canvas.draw()
        fig.canvas.flush_events()
    except KeyboardInterrupt:
        break

ser.close()


##Save data to csv



# example data
datos_tiempo = x_data
datos_carga = y_data

# create a pandas DataFrame from the data
df = pd.DataFrame({'Tiempo': datos_tiempo, 'Carga': datos_carga})

# save the DataFrame to a CSV file
df.to_csv('datos_celda.csv', index=False)