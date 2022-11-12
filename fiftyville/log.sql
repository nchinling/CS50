-- Keep a log of any SQL queries you execute as you solve the mystery.
--1. To start running database queries
sqlite3 fiftyville.db

--2. Query the different types of tables available
.tables
airports              crime_scene_reports   people
atm_transactions      flights               phone_calls
bakery_security_logs  interviews
bank_accounts         passengers

--3. Query to know the columns in each table
.schema airports
.schema atm_transactions
.schema bakery_security_logs
.schema bank_accounts
.schema crime_scene_reports
.schema flights
.schema interviews
.schema passengers
.schema people
.schema phone_calls


--4. To read the crime scene report. Crime id is 295
SELECT description, id FROM crime_scene_reports
WHERE street = "Humphrey Street" AND day = 28
AND month = 7 AND year = 2021;

--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

--5. To read transcript from the three witnesses
SELECT transcript FROM interviews
WHERE year = 2021 AND
month = 7 AND day = 28;

--Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
--I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
--As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

--Next step. 1. Read ATM log 8-10:15am 2. Flight ticket for 29 July. 3. Security footage for 10:15 - 10:30 4. Phone call for 10:15 - 10:30

--Identify name and number of caller
SELECT name, caller FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

-- +---------+----------------+
-- |  name   |     caller     |
-- +---------+----------------+
-- | Sofia   | (130) 555-0289 |
-- | Kelsey  | (499) 555-9472 |
-- | Bruce   | (367) 555-5533 |
-- | Kelsey  | (499) 555-9472 |
-- | Taylor  | (286) 555-6063 |
-- | Diana   | (770) 555-1861 |
-- | Carina  | (031) 555-6622 |
-- | Kenny   | (826) 555-1652 |
-- | Benista | (338) 555-6650 |

--List is trimmed to 9 suspects

-- Find common person who made phone call and withdrew money from ATM at Legged Street
SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60 AND people.name IN (
    SELECT name FROM people
    JOIN bank_accounts ON bank_accounts.person_id = people.id
    JOIN atm_transactions on atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Leggett Street"
    AND atm_transactions.transaction_type = "withdraw"
);

--List is trimmed to 5
-- +---------+
-- |  name   |
-- +---------+
-- | Bruce   |
-- | Diana   |
-- | Kenny   |
-- | Taylor  |
-- | Benista |
-- +---------+


-- Find people who flew out on 29 July
SELECT name FROM people
JOIN passengers on passengers.passport_number = people.passport_number
JOIN flights on flights.id = passengers.flight_id
WHERE flights.year = 2021 AND
flights.month = 7 AND
flights.day = 28;

-- Combine with previous list
SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60 AND people.name IN (
    SELECT name FROM people
    JOIN bank_accounts ON bank_accounts.person_id = people.id
    JOIN atm_transactions on atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Leggett Street"
    AND atm_transactions.transaction_type = "withdraw" AND people.name IN (
        SELECT name FROM people
        JOIN passengers on passengers.passport_number = people.passport_number
        JOIN flights on flights.id = passengers.flight_id
        WHERE flights.year = 2021 AND
        flights.month = 7 AND
        flights.day = 28
        )
);


-- +--------+
-- |  name  |
-- +--------+
-- | Bruce  |
-- | Diana  |
-- | Kenny  |
-- | Taylor |
-- +--------+

-- to find earlies hour that flight on 29 July flew out
select min(hour) from flights;

-- Answer is 7am

-- Combine with previous list
SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60 AND people.name IN (
    SELECT name FROM people
    JOIN bank_accounts ON bank_accounts.person_id = people.id
    JOIN atm_transactions on atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Leggett Street"
    AND atm_transactions.transaction_type = "withdraw" AND people.name IN (
        SELECT name FROM people
        JOIN passengers on passengers.passport_number = people.passport_number
        JOIN flights on flights.id = passengers.flight_id
        WHERE flights.year = 2021 AND
        flights.month = 7 AND
        flights.day = 28 AND
        flights.hour < 9
        )
);

+--------+
|  name  |
+--------+
| Bruce  |
| Kenny  |
| Taylor |
+--------+

-- join with airport table

SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60 AND people.name IN (
    SELECT name FROM people
    JOIN bank_accounts ON bank_accounts.person_id = people.id
    JOIN atm_transactions on atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Leggett Street"
    AND atm_transactions.transaction_type = "withdraw" AND people.name IN (
        SELECT name FROM people
        JOIN passengers on passengers.passport_number = people.passport_number
        JOIN flights on flights.id = passengers.flight_id
        JOIN airports on airports.id = flights.destination_airport_id
        WHERE flights.year = 2021 AND
        flights.month = 7 AND
        flights.day = 28 AND
        flights.hour < 9 AND
        airports.full_name = "Fiftyville Regional Airport" AND people.license_plate IN (



        )

        )
);

--query from bakery_security_logs to get license plate number
SELECT license_plate FROM bakery_security_logs
WHERE year = 2021 AND
month = 7 AND
day = 28 AND
hour = 10 AND
minute BETWEEN 15 AND 25 AND
activity = "exit";


--merge main table with person's license_plate







AND people.license_plate IN (



        )



cat test.sql | sqlite3 fiftyville.db
sqlite3 fiftyville.db
