#pragma once

//Handle parallel tasks through multithreading. Be cautious of data races when using
class CE_Sequence final
{
    using Job = std::function<void()>;

private:

    std::vector<Job> _jobs;
    std::vector<std::jthread> _threads;

public:

    CE_Sequence();
    CE_Sequence(std::vector<Job>& jobs);
    ~CE_Sequence();

    void AddJob(const Job& job) noexcept { _jobs.push_back(job); }
    void AddJob(std::vector<Job>& jobs) noexcept { _jobs.swap(jobs);}

    void RunJobs()
    {
        for (auto& job : _jobs)
        {
            _threads.push_back(std::jthread(job));
        }
    }

    void WaitEndJobs()
    {
        for (auto& job : _threads)
        {
            if (job.joinable())
            {
                job.join();
            }
        }
    }
};

using Sequence = CE_Sequence; //Redefined