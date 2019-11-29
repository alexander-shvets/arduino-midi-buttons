const SerialPort = require('serialport')
const {Output}   = require('easymidi')

const output = new Output('MadMapper In')

main()
async function main(){

    const serial = new SerialPort(
        await getArduinoDevicePath(), 
        { lock: false }
    )

    serial.on('data',  buffer => {
        const buttonNum = buffer.toString()
        if( buttonNum ){
            sendMidi( buttonNum )
        }
    })
}

function sendMidi( buttonNum ){
    // https://www.npmjs.com/package/easymidi#message-reference
    console.log('Control Change:', buttonNum )
    output.send('cc', {
        controller: buttonNum,
        value: 127
    })
}

async function getArduinoDevicePath(){
    const [{path}] = ( await SerialPort.list() ).filter(
        ({manufacturer}) => manufacturer && manufacturer.indexOf('Arduino') === 0
    )
    //console.log( path )
    return path
}