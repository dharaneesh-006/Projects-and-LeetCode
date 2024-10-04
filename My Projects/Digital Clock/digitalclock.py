from tkinter import *
from tkinter.ttk import * 
from time import strftime

root = Tk()
root.title("Digital Clock")


label = Label(root, font=("Arial",100),background = "black",foreground = "orange")
label.pack(anchor='center')

def time():
    current_time = strftime("%I:%M:%S %p")
    label.config(text = current_time)
    label.after(500,blank)
    label.after(1000,time)
def blank():
    current_time = strftime("%I:%M   %p")
    label.config(text = current_time)
time()
mainloop()
