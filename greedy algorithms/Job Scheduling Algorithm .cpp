// QUESTION : We are given array of jobs, Job contains the job's deadline and it's profit. We need to find the maximum profit that can be gained.

// THOUGHT PROCESS
// Basically what we do is we take that job first whose profit is max and will do it on it's deadline , if that slot is free.
// and by doing this what happens is that sabse bade profit sabse phle hore and jitna deadline ke paas hai utna paas hora
// That's why max jobs can be done.
// Now to manage the slots , we create an array of size 'maxTime' (which is the maximum deadline time among all the jobs).

// ALGORITHM : GREEDY

// First we sort the array accourding to the profit.
// 2) Now we iterate over the array and then caluate the maximum deadline among all the jobs available [ie. maxTime]
// 3) Now we create an array 'timeslots' that will check if that paticular timeslot is free or not
// 4) Now we take the first job (ie the one with maximum profit)
// 4.1) Now starting from the point of it's deadline we keep checking the timeslot if it's free or not and if it's free we fill that spot
// and add that job's profit to the total_profit ( also break the loop ), otherwise we keep checking the previous timeslots
// 5) Now return the jobcount and total_profit.
// CODE :

class JobSequencing
{
    struct Job
    {
        int id;     // Job Id
        int dead;   // Deadline of job
        int profit; // Profit if job is over before or on deadline
    };

    bool comparitor(Job max, Job min)
    {
        return max.profit > min.profit;
    }
    pair<int, int> JobScheduling(Job jobs[], int n)
    {
        sort(jobs, jobs + n, comparitor);
        int profit = 0;//This variable will store the total profit gained
        int maxTime = 0;//This will be used to get the maximum limit of array , in which i will store that job
        int jobCount = 0;//This will store the No. of jobs that can be done.

        for (int i = 0; i < n; i++)
        {
            maxTime = max(maxTime,jobs[i].dead);
        }

        vector<int> timeslots(maxTime + 1, false); //This vector will store at what time which job has been done

        for (int i = 0; i < n; i++)
        {
            Job currJob = jobs[i];

            for (int t = currJob.dead; t > 0; t--)
            {
                if (timeslots[t] == false)
                {
                    timeslots[t] = true;
                    profit += currJob.profit;
                    jobCount++;
                    break;
                }
            }
        }
        return {jobCount, profit};
    }
};
