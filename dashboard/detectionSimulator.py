import json
import time
import random

sensor = ["Livre", "Ocupado"]
mesa = [0, 1, 2, 3, 4]

while(1):
    file = open('data.json', 'r+')
    data = json.load(file)
    mesaTmp = random.choice(mesa)
    movTmp = random.choice(sensor)
    # print(mesaTmp)
    # print(movTmp)
    data["leic"][mesaTmp]["sensor"] = movTmp

    file.seek(0)
    json.dump(data, file)
    file.truncate()
    file.close()
    time.sleep(5)

