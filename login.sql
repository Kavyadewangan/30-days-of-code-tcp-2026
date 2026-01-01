CREATE DATABASE fridgie_db;

USE fridgie_db;

CREATE TABLE users (
  id INT AUTO_INCREMENT PRIMARY KEY,
  username VARCHAR(100) NOT NULL UNIQUE,
  password VARCHAR(255) NOT NULL
);

-- Add a test user
INSERT INTO users (username, password)
VALUES ('admin', '1234');
