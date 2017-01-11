# Python 3.3.3 and 2.7.6
# python helloworld_python.py

from threading import Thread

i = 0

def thread1():
    global i
    for j in range (0, 1000000):
        i+=1

def thread2():
    global i
    for j in range (0, 1000000):
        i-=1


def main():
    thr1 = Thread(target = thread1, args = (),)
    thr1.start()

    thr2 = Thread(target = thread2, args = (),)
    thr2.start()
    
    thr1.join()
    thr2.join()
    print("i =", i)


main()
