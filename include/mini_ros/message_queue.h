#ifndef MESSAGE_QUEUE_H_
#define MESSAGE_QUEUE_H_

#include <queue>
#include <condition_variable>
#include <mutex>
#include "message.h"

namespace mini_ros {

class MessageQueue {

public:
  MessageQueue() : max_size(0) {}
  MessageQueue(size_t max_size);
  using MessagePair = std::pair<std::string, std::shared_ptr<Message>>;
  MessagePair front();
  void pop();
  void push(MessagePair &msg);
  bool empty();
  void wait();
  void notify();

private:
  std::queue<MessagePair> msg_queue;
  std::condition_variable cv;
  std::mutex mtx;
  std::mutex mtx_cv;
  size_t max_size;
};
}
#endif
