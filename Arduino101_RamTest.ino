/* Arduino 101 SRAM test
 *  Based on an example at: 
 *  https://github.com/mpflaga/Arduino-MemoryFree/issues/6
 * 
 */

uint32_t getFreeRam() {
    uint32_t stackTop;
    uint32_t heapTop;

    // current position of the stack.
    stackTop = (uint32_t) &stackTop;

    // current position of heap.
    void* hTop = malloc(1);
    heapTop = (uint32_t) hTop;
    free(hTop);

    // The difference is the free, available ram.
    return stackTop - heapTop;
}

/*
uint32_t getfreeUnoRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  int fr = (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
  Serial.print("Free ram: ");
  Serial.println(fr);

}*/

void allocationTest(uint16_t _size)
{
    void *test = malloc(_size);

    if(!test)
    {
        Serial.print("Malloc failed for: ");
        Serial.println(_size);
        return;
    }
    
    Serial.print("Allocation: ");
    Serial.print(_size);
    Serial.print(" RAM: ");
    Serial.println(getFreeRam());
    
    free(test);
}

void setup() 
{
    while (!Serial) 
    {
        ; //wait for serial
    }
    Serial.begin(9600);
    
    //TEST
    allocationTest(1);
    allocationTest(512);
    allocationTest(1024);
    allocationTest(2048);
    allocationTest(3072);
    allocationTest(1);
  
}

void loop() 
{
  

}
