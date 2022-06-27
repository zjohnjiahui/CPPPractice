#ifndef _CHRONO_TIMER_H_
#define _CHRONO_TIMER_H_

#include <chrono>
#include <iostream>
#include <string>

class ChronoTimer
{
  enum STATE {START, END, PAUSE, RESUME};
public:
  enum TIME_TYPE { SECONED, MILLI, MICRO };

private:
  std::chrono::time_point<std::chrono::steady_clock> m_start;
  std::chrono::time_point<std::chrono::steady_clock> m_end;
  long long m_elapse;

  TIME_TYPE m_type;
  STATE m_state;

  void accumulate() {
    switch (m_type) {
    case SECONED: m_elapse += std::chrono::duration_cast<std::chrono::seconds>(m_end - m_start).count(); break;
    case MILLI: m_elapse += std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count(); break;
    case MICRO: m_elapse += std::chrono::duration_cast<std::chrono::microseconds>(m_end - m_start).count(); break;
    default:break;
    }
  }

public:
  ChronoTimer() :m_type(MILLI), m_state(END) {}
  ChronoTimer(TIME_TYPE time_type) :m_type(time_type), m_state(END) {}

  void start() {
    if (m_state == END) {
      m_start = std::chrono::steady_clock::now();
      m_elapse = 0;
      m_state = START;
    }
  }

  void end() {
    if (m_state == START || m_state == RESUME) {
      m_end = std::chrono::steady_clock::now();
      accumulate();
      m_state = END;
    }
  }

  void pause()
  {
    if (m_state == START || m_state == RESUME) {
      m_end = std::chrono::steady_clock::now();
      accumulate();
      m_state = PAUSE;
    }
  }

  void resume()
  {
    if (m_state == PAUSE) {
      m_start = std::chrono::steady_clock::now();
      m_state = RESUME;
    }
  }

  void end_print(std::string str) {
    end();
    std::cout << str << " :";
    print_elapse();
  }

  // description: print the elapsed time
  void print_elapse() {
    if (m_state == PAUSE || m_state == END) {
      switch (m_type) {
      case SECONED: std::cout << m_elapse << "s" << std::endl; break;
      case MILLI: std::cout << m_elapse << "ms" << std::endl; break;
      case MICRO: std::cout << m_elapse << "us" << std::endl; break;
      default:break;
      }
    }
  }
};

#endif
