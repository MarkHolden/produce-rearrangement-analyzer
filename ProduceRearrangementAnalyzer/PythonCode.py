def SaveHistogramData():
    frequencyFile = open("frequency.dat", "w+")
    for k, v in sorted(GetProduceDict().items(), key=lambda x: x[1], reverse=True):
        frequencyFile.write("{} {}\n".format(k, v))

def PrintFrequencies():
    print("\nProduce Item Frequencies")
    for k, v in sorted(GetProduceDict().items(), key=lambda x: x[1], reverse=True):
        print("Item:", f'{k:16}', "\tQuantity:", v)

def GetItemFrequency(searchTerm: str) -> int:
    produceDict = GetProduceDict()
    return produceDict[searchTerm] if searchTerm in produceDict else 0

def GetProduceDict() -> dict:
    produceList = open("ProduceInput.txt")
    produceDict = {}
    for inputString in produceList:
        produce = inputString.rstrip('\n')
        if produce in produceDict:
            produceDict[produce] = produceDict[produce] + 1
        else:
            produceDict[produce] = 1
    return produceDict