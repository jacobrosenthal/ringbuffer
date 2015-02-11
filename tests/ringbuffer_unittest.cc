#include "../ringbuffer.h"
#include "gtest/gtest.h"

TEST(RingBufferTest, Available) {
  ringbuffer w(1);
  EXPECT_EQ(0, w.available());
  w.push('a');
  EXPECT_EQ(1, w.available());
}

TEST(RingBufferTest, Peek) {
  ringbuffer w(1);
  w.push('a');
  EXPECT_EQ('a', w.peek());
}

TEST(RingBufferTest, Pop) {
  ringbuffer w(1);
  w.push('a');
  EXPECT_EQ('a', w.pop());
  EXPECT_EQ(0, w.available());
}

TEST(RingBufferTest, WrapHead) {
  ringbuffer w(1);
  w.push('a');
  w.push('b');
  EXPECT_EQ('a', w.pop());
}

TEST(RingBufferTest, WrapTail) {
  ringbuffer w(1);
  w.push('a');
  EXPECT_EQ('a', w.pop());
  EXPECT_EQ('a', w.pop());
}
