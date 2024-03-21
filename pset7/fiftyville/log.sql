-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28;

-- فقط چک کردم ببینم نظر افراد در این روز چه بوده
SELECT * FROM interviews WHERE month = 7 AND day = 28;
--PRKING LOG
SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 40 AND activity = "exit";

--NAME- PARKING:
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 40 AND activity = "exit");

--BANK LOG
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Leggett Street";
-- NAME BANK:
SELECT COUNT(person_id) FROM bank_accounts;
SELECT id FROM people;
SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Leggett Street");

--join bank and parking:

SELECT * FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Leggett Street") AND people.name in (SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 25 AND minute < 40 AND activity = "exit"));

--PHONE:

SELECT receiver  FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 65;
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 65 AND caller = "(286) 555-6063";

-- PHONE NAME:
SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 65);
SELECT * FROM people WHERE phone_number = "(676) 555-6554";
-- FLIGHT NUMBER:
SELECT * FROM passengers WHERE passport_number = 1988161715;
SELECT * FROM flights WHERE flights.day = 29;
SELECT * FROM airports;
SELECT * FROM flights JOIN airports ON airports.id = flights.id WHERE flights.day = 29;