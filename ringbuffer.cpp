#include "ringbuffer.h"

ringbuffer::ringbuffer(size_t size)
        : size(size)
        , head(0)
        , tail(0)
        , readLast(true)
        , buffer(new unsigned char[size])
{}

ringbuffer::~ringbuffer()
{
  delete[] buffer;
}

//drops on overwrite
void ringbuffer::push(unsigned char c)
{
  //detect full and drop
  if(isFull()){
    return;
  }

  buffer[head] = c;
  head = (head + 1) % size;
  readLast = false;
}

unsigned char ringbuffer::pop()
{
  unsigned char c = buffer[tail];
  if(!available()){
    return c;
  }
  tail = (tail + 1) % size;
  readLast = true;
  return c;
}

unsigned char ringbuffer::peek()
{
  return buffer[tail];
}

bool ringbuffer::isFull()
{
  return (head == tail && !readLast);
}

int ringbuffer::available()
{
  int available = (((head + size) - tail) % size);

  //empty/full case
  if(!available)
  {
    if(readLast){
      return 0;
    }

    return size;
  }

  return available;
}