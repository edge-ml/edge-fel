import csv
import serial
import predictor

default_params = {
    "mean_n_abs_max_n": 8,
    "change_quantile_lower": -0.1,
    "change_quantile_upper": 0.1,
    "change_quantile_aggr": 0,
    "range_count_lower": -1,
    "range_count_upper": 1,
    "count_above_x": 0,
    "count_below_x": 0,
    "quantile_q": 0.5,
    "autocorrelation_lag": 1,
    "mfcc_sampling_rate": 100,
    "mfcc_num_filter": 48,
    "mfcc_m": 1,
    "lpc_auto_n": 10,
    "lpc_n": 10,
    "lpcc_auto_n": 10,
    "lpcc_n": 10,
    "lpcc_cep_length": 10
}


def default_params_to_string():
    string_params = ""
    for param, value in default_params.items():
        string_params += param + ":" + str(value) + " "
    return string_params[:-1]


def default_mode():
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
    params = input("Enter params: ")
    if params == "default":
        params = default_params_to_string()
    elif params == "none":
        params = ""
    arduino_input = "transfer data of size\n" + str(data_size) + arduino_input + "\n" + features + "\n" + params + "\n"
    port.write(bytes(arduino_input, 'utf-8'))
    print(port.read_until('Close session\n', 100000).decode())


def collect_mode():
    board = input("Enter connected Arduino board: ")
    params = input("Enter params: ")
    if params == "default":
        params = default_params_to_string()
    elif params == "none":
        params = ""
    header_written = False
    path = "runtime_results/runtimes_" + board + ".csv"
    with open(path, "w", newline='') as f:
        writer = csv.writer(f)
        data_size = 10
        while data_size <= 2000:
            arduino_input = ""
            k = 0
            j = 0
            while k < data_size:
                if not j < len(data):
                    j = 0
                arduino_input += " " + str(data[j])
                k += 1
                j += 1

            arduino_input = "transfer data of size\n" + str(
                data_size) + arduino_input + "\nall_iterative\n" + params + "\n"
            port.write(bytes(arduino_input, 'utf-8'))

            output = port.readlines()
            if not header_written:
                header = ["size", "data_transfer", "feature_transfer", "param_transfer"]
                for line in output:
                    if ":" in line.decode():
                        header.append(line.decode().split()[0].strip(":"))
                writer.writerow(header)
                header_written = True
            body = [data_size]
            for line in output:
                if ":" in line.decode():
                    body.append(int(line.decode().split()[3]))
                elif "," in line.decode():
                    body.append(int(line.decode().split()[4]))
            writer.writerow(body)
            if data_size < 100:
                data_size += 10
            else:
                data_size += 100


mode = input("Enter user mode (default/collect/predict): ")
port = serial.Serial('COM4', 115200, timeout=1)
running = True
while running:
    dataset_name = input("Enter path to dataset: ")
    if not dataset_name == "default":
        file = open(dataset_name)
    else:
        file = open("datasets/data_random.csv")
    reader = csv.reader(file)
    data = list(next(reader))

    if mode == "default":
        default_mode()
    elif mode == "collect":
        collect_mode()
    elif mode == "predict":
        predictor.run()
    running = bool(str(input("Continue? (y/enter): ")))

port.close()

# Regex Daten: "transfer data of size\n{int size} {float values}\n{string features}\n{string params}\n"
# params = name:value name:value
