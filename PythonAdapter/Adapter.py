import serial
port = serial.Serial('COM3', 115200, timeout=1)
running = True
while running:
    features = input("Enter features: ")
    port.write(bytes(features + "\n", 'utf-8'))
    print(port.read_until('Close session\n', 10000).decode())
    running = bool(str(input("Continue? (y/enter): ")))

port.close()
