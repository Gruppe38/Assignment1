# Python 3.3.3 and 2.7.6
# python helloworld_python.py

import threading

i = 0
lock = threading.Lock()

def thread1():
    global i
    for j in range (0, 1000000):
    	lock.acquire()
        i+=1
        lock.release()

def thread2():
    global i
    for j in range (0, 1000001):
        lock.acquire()
        i-=1
        lock.release()


def main():
    thr1 = threading.Thread(target = thread1, args = (),)
    thr2 = threading.Thread(target = thread2, args = (),)

    thr1.start()
    thr2.start()
    
    thr1.join()
    thr2.join()
    print("i =", i)


main()
