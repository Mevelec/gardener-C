#pragma once

#include "pch.h"
#include "recurence/recurence.h"
#include <ctime>
#include <set>

namespace Calendar {
    class Event {
        public:
            Event() : title(""), beginDate(0), endDate(0), recurence(Recurence::NONE) {}
            Event(const std::string& title, const time_t& beginDate, const time_t& endDate, Recurence recurence = Recurence::NONE)
                : title(title), beginDate(beginDate), endDate(endDate), recurence(recurence) {}
        
            // Get next occurrence after a given date
            time_t getNextOccurrence(const time_t afterDate) const;
            // Generate upcoming occurrences within a date range
            std::set<time_t> getOccurrencesBetween(const time_t startDate, const time_t endDate) const;
            // Generate the next x occurrences after a given date
            std::set<time_t> getNextOccurrences(int x, const time_t afterDate) const;
            
        private:
            std::string title;
            time_t beginDate;
            time_t endDate;
            Recurence recurence;

            // Calculate the next occurrence to the given date
            time_t calculateNextOccurrence(time_t date) const;
        };
};