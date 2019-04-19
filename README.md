# Data-Base-yellow-belt-
Database that works with pairs (date, event).

## A set of commands to work with the database
- **Add date event** — add a pair(date, event) to the database;
- **Print** — show all database contents;
- **Find condition** - show all records contained in the database that satisfy the **_condition_**;
- **Del condition** - remove from the database all records that satisfy the **_condition_**;
- **Last date** - display a record with the latest event that happened not later than the date;

## How to write a condition
Implemented comparison operators: ```<, <=, >=, >, ==, !=```.
A condition may consist of several sub-conditions that are connected by logical OR / AND.
### Example:
- ```Find date < 2017-11-06``` - find all the events that happened before November 6, 2017 and show them;
- ```Del event != "holiday"``` - remove from the database all events except **"holiday"**.
- ```Find date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport event"``` - find all the events **"sport event"** that occurred in the first half of 2017;
- ```Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event")``` - remove from the database all the events **"holiday"** and **"sport event"** that happened before 2017.
