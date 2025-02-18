import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd

# Function to play sound corresponding to a bar height
def play_tone(frequency, duration=0.1, sample_rate=44100):
    t = np.linspace(0, duration, int(sample_rate * duration), endpoint=False)
    sine_wave = np.sin(2 * np.pi * frequency * t)
    sd.play(sine_wave, samplerate=sample_rate)
    sd.wait()

# Generate random bars
amount = 10
lst = np.random.randint(400, 1000, amount)
x = np.arange(0, amount, 1)

# Sorting Algorithm with Visualization and Sound
n = len(lst)
mini = min(lst)
maxi = max(lst)
plt.figure()
for i in range(n):
    for j in range(n - i - 1):
        plt.bar(x, lst)
        plt.pause(0.1)
        plt.clf()
        
        # If swap happens, play sound
        if lst[j] > lst[j + 1]:
            lst[j], lst[j + 1] = lst[j + 1], lst[j]
            
            # Map bar height to frequency
            min_freq, max_freq = 200, 1000
            freq = min_freq + (lst[j] - mini) / (maxi - min(lst)) * (max_freq - min_freq)
            
            # Play corresponding tone
            play_tone(freq, 0.5)

plt.bar(x, lst, color="green")
plt.show()
