from pocketsphinx import LiveSpeech
import socket

ip = '192.168.254.200'
port = 80


conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

conn.connect((ip,port))
print('Listening')


speech = LiveSpeech(lm=False,kws='keyword.list')

# an for in loop to iterate in speech+
for phrase in speech:
        # printing if the keyword is spoken with segments along side.
    word = (phrase.segments(detailed=False))
    print(word[0])
    transfer = word[0]
    data = transfer
    
  
    match transfer:
        case "go ":
            print('Moving forward sir!')
            conn.send(data.encode())
        case "south ":
            print('Reversing Sir!')
            conn.send(data.encode())
        case "east ":
            print('Turning East Sir!')
            conn.send(data.encode())
        case "west ":
            print('Turning West Sir!')
            conn.send(data.encode())
        case "stop ":
            print('Terminating Operations Sire!')
            conn.send(data.encode())
        case _:
            print("No commands issued yet sire!")
            conn.send(data.encode())
    

        

