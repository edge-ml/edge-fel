import csv
import serial


def normal_mode():
    arduino_input = ""
    data_size = int(input("Enter requested size of data: "))
    i = 0
    j = 0
    while i < data_size:
        if not j < len(data):
            j = 0
        arduino_input += " " + str(data[j])
        i += 1
        j += 1
    features = input("Enter features: ")
    arduino_input = "transfer data of size\n" + str(data_size) + arduino_input + "\n" + features + "\n"
    port.write(bytes(arduino_input, 'utf-8'))
    print(port.read_until('Close session\n', 10000).decode())


def collect_mode():
    board = input("Enter connected Arduino board: ")
    header_written = False
    path = "runtime_results/runtimes_" + board + ".csv"
    with open(path, "w", newline='') as f:
        writer = csv.writer(f)
        for data_size in range(100, 3100, 100):
            arduino_input = ""
            k = 0
            j = 0
            while k < data_size:
                if not j < len(data):
                    j = 0
                arduino_input += " " + str(data[j])
                k += 1
                j += 1

            arduino_input = "transfer data of size\n" + str(data_size) + arduino_input + "\nall_iterative\n"
            port.write(bytes(arduino_input, 'utf-8'))

            output = port.readlines()
            if not header_written:
                header = ["size"]
                for line in output:
                    if ":" in line.decode():
                        header.append(line.decode().split()[0].strip(":"))
                writer.writerow(header)
                header_written = True
            body = [data_size]
            for line in output:
                if ":" in line.decode():
                    body.append(int(line.decode().split()[3]))
            writer.writerow(body)


mode = input("Enter user mode (normal/collect): ")
port = serial.Serial('COM3', 115200, timeout=1)
running = True
while running:
    dataset_name = input("Enter path of dataset: ")
    if not dataset_name == "default":
        file = open(dataset_name)
    else:
        file = open("datasets/data_1k.csv")
    reader = csv.reader(file)
    data = list(next(reader))

    if mode == "normal":
        normal_mode()
    elif mode == "collect":
        collect_mode()

    running = bool(str(input("Continue? (y/enter): ")))

port.close()

# Regex Daten: "transfer data of size\n{int size} {float values}\n{string features}\n
