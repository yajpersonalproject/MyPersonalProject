import speech_recognition as sr #google voice recognition API
import keyboard #keyboard module python

r = sr.Recognizer()

while(True):
    with sr.Microphone() as source:
        try:
            audio = r.listen(source)
            text = r.recognize_google(audio)
            keyboard.write(text, delay=0)
            keyboard.press("enter")
            keyboard.release("enter")
        except:
            audio = r.listen(source)
            text = r.recognize_google(audio)
            keyboard.write(text, delay=0)
            keyboard.press("enter")
            keyboard.release("enter")
