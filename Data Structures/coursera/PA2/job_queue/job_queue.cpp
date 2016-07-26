#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;

struct Worker 
{
  int id;
  long long next_free_time;
};

struct compare  
 {  
   bool operator()(const Worker& l, const Worker& r)  
   {  
       return l.next_free_time > r.next_free_time || (l.next_free_time == r.next_free_time && l.id > r.id);  
   }  
 };  


class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  std::priority_queue<Worker, std::vector<Worker>, compare> worker_pool;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {

    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    // Initialize worker pool
    for (int i = 0; i < num_workers_; ++i) {
      Worker w; 
      w.id = i;
      w.next_free_time = 0;
      worker_pool.push(w);
    }
     

    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      Worker next_worker;

      next_worker = worker_pool.top();
      worker_pool.pop();
      
      assigned_workers_[i] = next_worker.id;
      start_times_[i] = next_worker.next_free_time;

      next_worker.next_free_time += duration;
      worker_pool.push(next_worker);      
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
