Serial to MIDI bridge.

## Install

0. Download and install [Node.js](https://nodejs.org/)

1. Open Command Prompt and type:

```Shell
git clone git@github.com:silapidpisu/arduino-midi-buttons.git || (echo "Please download and unzip into folder 'arduino-midi-buttons'..." && start https://github.com/silapidpisu/arduino-midi-buttons/archive/master.zip && pause)
cd arduino-midi-buttons
npm install 
```

## Run

1. Open MadMapper
2. On Command Line type:

```
npm start
```

## ToDo

- [ ] Use WebUSB API instead of native `serialport` module to incrase portability.
