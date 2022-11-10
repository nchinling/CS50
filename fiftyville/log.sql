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


--4. 
