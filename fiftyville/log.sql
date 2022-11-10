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


--4. To read the crime scene report
SELECT description, id FROM crime_scene_reports
WHERE street = "Humphrey Street" AND day = 28
AND month = 7 AND year = 2021;

--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |

--5.
SELECT transcript FROM interviews
WHERE year = 2021 AND
month = 7 AND day = 28 AND id =295;

SELECT transcript FROM interviews
WHERE id = 295;