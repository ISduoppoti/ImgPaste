from PIL import ImageGrab
import datetime as dt

img = ImageGrab.grabclipboard()
current_time = dt.datetime.now()
img_name = str(current_time.year)+'-'+str(current_time.month)+'-'+str(current_time.day)+'-'+str(current_time.microsecond)+'.png'

img.save(img_name, 'PNG')