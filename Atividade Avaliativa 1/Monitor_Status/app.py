from flask import Flask, render_template
import serial
import time

# Configura a porta serial correta
try:
    arduino = serial.Serial('COM3', 9600, timeout=1)
    time.sleep(2)
except serial.SerialException as e:
    print(f"Erro ao conectar com o Arduino: {e}")
    arduino = None

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/control/<action>')
def control(action):
    if arduino:
        if action == 'on':
            arduino.write(b'A')  # Liga LED
            return "LED ligado (Aberta)"
        elif action == 'off':
            arduino.write(b'a')  # Desliga LED
            return "LED desligado (Fechada)"
        else:
            return "Comando inválido."
    else:
        return "Arduino não conectado."

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)
