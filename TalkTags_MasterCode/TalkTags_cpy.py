from digitalio import DigitalInOut, Direction, Pull
import board
import time
from adafruit_circuitplayground import cp
from adafruit_circuitplayground.express import cpx

# button
button_1 = DigitalInOut(board.A1)
button_1.direction = Direction.INPUT
button_1.pull = Pull.UP

cp.pixels.brightness = 0.3

while True:
    if not button_1.value:
        print("Button activated")
        cp.pixels[2] = (0, 255, 0)
        if cp.touch_A2:
            print("Touched A2!")
            cpx.play_file("a.wav")
            cp.pixels.fill((0, 50, 50))
            time.sleep(1)
        if cp.touch_A6:
            print("Touched A6!")
            cpx.play_file("b.wav")
            cp.pixels.fill((50, 0, 50))
            time.sleep(1)
        else:
            cp.pixels.fill((0, 0, 0))
    else:
        cp.pixels.fill((0, 0, 0))