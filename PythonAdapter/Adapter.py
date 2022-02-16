import serial
port = serial.Serial('COM3', 115200, timeout=1)
port.write(bytes('all_iterative\n', 'utf-8'))
print(port.read_until('Close session\n', 10000).decode())
port.close()
