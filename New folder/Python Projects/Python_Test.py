import tkinter as tk
#from tkinter import ttk
import ttkbootstrap as ttk

def convert():
    mile_input = entry_int.get()
    km_output = mile_input * 1.61
    print(entry_int.get())
    output_string.set(km_output)

# create a window
window = ttk.Window(themename ='darkly')
window.title("Demo")
window.geometry("")

#title
title_label = ttk.Label(master = window, text = 'Miles to Kilometers', font = 'Arial 24  bold')
title_label.pack()

#input field ( the input and buttons )
input_frame = ttk.Frame(master = window)
#creates a seperate variable that stores and updates valies 
#like a reg int from c++
entry_int = tk.IntVar()
entry =  ttk.Entry(master = input_frame, textvariable = entry_int)
button = ttk.Button(master = input_frame, text = 'Convert', command = convert )
#putting the button into the main window
entry.pack(side ='left', padx = 10)
button.pack(side = 'left') 
input_frame.pack(pady = 10)

#output
output_string = tk.StringVar()
output_label = ttk.Label(
    master = window, 
    text = 'Output', 
    font = 'Arial 24  bold', 
    textvariable  = output_string)
output_label.pack(pady = 10)

# run the event loop
window.mainloop()

