from speech_recognition import *
import serial
import time

colours = ["red colour", "green", "yellow", "turn on", "turn off"]

def audio_input():
    """return value is the string format of the voice input"""
    try:
        r = Recognizer()
        with Microphone() as source:
            inp = r.listen(source)
        a = r.recognize_google(inp)
        return a

    except UnknownValueError:
        print("please repeat your input")
        return (audio_input())

ard = serial.Serial("COM3", 9600)
time.sleep(2)
while True:
    text = audio_input().lower()
    print("Text:", text)

    if "stop" in text:
        break
    for colour in colours:
        if colour in text:
            byte_text = bytes(str.encode(colour))
            print("Byte_text:", byte_text)
            ard.write(byte_text)
