import pyautogui
import time
import pyperclip

def autotyper(speed=0.005):
    # Delay before starting
    time.sleep(5)

    # Get the content from the clipboard
    clipboard_content = pyperclip.paste()

    # Type the content with speed control
    pyautogui.typewrite(clipboard_content, interval=speed)

if __name__ == "__main__":
    # Adjust the speed by changing the argument (e.g., speed=0.05 for faster typing)
    autotyper(speed=0.01)


