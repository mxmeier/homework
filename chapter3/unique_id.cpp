#include <atomic>
#include <chrono>


class unique_id{
  /** A unique identifier.
   *
   * The identifier is specific to this process on this machine,
   * with the start time of the process recorded to be unique across
   * sequential runs.
   *
   * Note that forking is not allowed - handling this increases
   * constructor cost by 5x.
   *
   * Another limiting factor is that only 2^64 ids are available.
   * This could be made larger if there was a need, again for
   * additional constructor cost.
   */
  public:
    unique_id() :
      pid_(global_pid_),
      time_(global_time_),
      cnt_(global_cnt_++)
    { }

    unique_id(const unique_id& rhs) :
        pid_(rhs.pid_),
        time_(rhs.time_),
        cnt_(rhs.cnt_)
    { }

    bool operator==(unique_id rhs) const {
      return (pid_ == rhs.pid_
              && time_ == rhs.time_
              && cnt_ == rhs.cnt_
             );
    }

  private:
    const static uint64_t global_pid_;
    const static uint64_t global_time_;
    static std::atomic<uint64_t> global_cnt_;

    uint64_t pid_;
    uint64_t time_;
    uint64_t cnt_;
};
const uint64_t unique_id::global_pid_ = static_cast<uint64_t>(getpid());
const uint64_t unique_id::global_time_ = std::chrono::system_clock::now().time_since_epoch().count();
std::atomic<uint64_t> unique_id::global_cnt_(0);
