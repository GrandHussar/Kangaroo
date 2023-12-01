import speech_recognition as sr
from pocketsphinx import LiveSpeech


recognize = sr.Recognizer()
keywords=[('go',0),('back',0),('left',0),('right',0)]


with sr.Microphone(device_index=1) as source:
    print("What's your command?: ")
    recognize.adjust_for_ambient_noise(source)
    audio = recognize.listen(source)
    word = recognize.record(audio,duration = 2)
    print("Recognizing Command.....")


    for phrase in audio:
            # printing if the keyword is spoken with segments along side.
        print(phrase.segments())
