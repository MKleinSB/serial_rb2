#include "pxt.h"

#define MICROBIT_SERIAL_READ_BUFFER_LENGTH 64

//% weight=2 color=#002050 icon="\uf287"
namespace serial_rb {
    /**
    * Sends a buffer through Serial connection
    */
    //% blockId=serial_writebuffer block="serial_rb|write buffer %buffer"
    //% shim=serial_rb::writeBuffer
    void writeBuffer(Buffer buffer) {
      if (!buffer) return;

      ManagedBuffer buf(buffer);
      uBit.serial.send(buf.getBytes(), buf.length());
    }
    
    /**
     * Reads multiple characters from the receive buffer and fills a user buffer.
     * @param length default buffer length, eg: 64
     */
    //% blockId=serial_readbuffer block="serial_rb|read buffer %length"
    //% shim=serial_rb::readBuffer
    Buffer readBuffer(int length) {
      if (length <= 0)
        length = MICROBIT_SERIAL_READ_BUFFER_LENGTH;
        
      ManagedBuffer buf(length);
      int read = uBit.serial.read(buf.getBytes(), buf.length());
      if (read != buf.length())
        buf = buf.slice(read);

      return buf.leakData();
    }
}
