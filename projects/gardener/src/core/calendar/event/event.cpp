#include "event.h"

namespace Calendar {
    // Get next occurrence after the given date
    time_t Event::getNextOccurrence(const time_t date) const {
        GA_CORE_TRACE(">> getNextOccurrence({0})", date);
        if (date < beginDate) {
            GA_CORE_TRACE("<< getNextOccurrence() => 0");
            return 0;
        }
        else {
            time_t current = beginDate;
            while (current <= date && current <= endDate) {
                current = calculateNextOccurrence(current);
            }
            GA_CORE_TRACE("<< getNextOccurrence()");
            return current;
        }
    }
    
    // Generate the next x occurrences after a given date
    std::set<time_t> Event::getNextOccurrences(int x, const time_t date) const {
        GA_CORE_TRACE(">> getNextOccurrences({0}, {1})", x, date);

        std::set<time_t> upcoming;
        time_t current = getNextOccurrence(date);
        if (current != 0 ) {
            for (int count = 0; count < x; ++count) {
                upcoming.emplace(current);
                current = calculateNextOccurrence(current);
                if (current == 0) break;
            }    
        }
        GA_CORE_TRACE("<< getNextOccurrences()");
        return upcoming;
    }

    // Generate upcoming occurrences within a date range
    std::set<time_t> Event::getOccurrencesBetween(const time_t a_Date, const time_t b_Date) const {
        GA_CORE_TRACE(">>getOccurrencesBetween({0}, {1})", a_Date, b_Date);

        std::set<time_t> upcoming;
        time_t current = getNextOccurrence(a_Date);
        if (current != 0 ) {
            upcoming.emplace(current);
            while (current != 0)
            {
                current = getNextOccurrence(a_Date);
                upcoming.emplace(current);
            }
            
        }
        GA_CORE_TRACE("<<getOccurrencesBetween()");
        return upcoming;
    }


    // Calculate the next occurrence based on Recurence type
    time_t Event::calculateNextOccurrence(time_t date) const {
        std::tm tm = *std::localtime(&date);

        switch (recurence) {
            case Recurence::DAILY:
                tm.tm_mday++;
                break;
            case Recurence::WEEKLY:
                tm.tm_mday += 7;
                break;
            case Recurence::MONTHLY:
                tm.tm_mon++;
                break;
            case Recurence::NONE:
                break;
        }
        return std::mktime(&tm); // Normalize and convert back to time_t
    }
};