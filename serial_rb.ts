 /**
     * serial_rb
     */
    //% weight=2 color=#002050 icon="\uf287"
declare namespace serial_rb {
        /**
         * Reads multiple characters from the receive buffer and fills a user buffer.
         * @param length default buffer length, eg: 64
         */
        //% blockId=serial_readbuffer block="serial_rb|read buffer %length"
        //% help=serial/read-buffer weight=5 
        //%shim=serial_rb::readBuffer
        export function readBuffer(length: number): Buffer;
        /**
         * Sends a buffer through Serial connection
         */
        //% blockId=serial_writebuffer block="serial_rb|write buffer %buffer"
        //% help=serial/write-buffer weight=6 
        //% shim=serial_rb::writeBuffer
        export function writeBuffer(buffer: Buffer): void;
}
