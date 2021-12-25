#include "speech_service.h"
#include <atomic>
#include <csignal>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

namespace {
std::atomic_bool exit_requested{false};
std::mutex mtx{};

void SignalHandler(int signum) {
  std::cout << "Signal handler called with signal : " << signum << std::endl;
  std::lock_guard<std::mutex> lock{mtx};
  exit_requested.store(true);
}

} // namespace

int main() {
  using SpeechService = intent_recognition::SpeechService;

  // Register signal handler
  signal(SIGINT, SignalHandler);
  SpeechService speech_service{exit_requested};

  auto th = std::thread([&speech_service]() { speech_service.GetIntent(); });

  if (th.joinable()) {
    th.join();
    std::cout << "Returned from other thread..." << std::endl;
  }

  return 0;
}
