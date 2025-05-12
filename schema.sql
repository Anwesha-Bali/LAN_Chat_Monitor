
CREATE TABLE ChatLogs (
    id SERIAL PRIMARY KEY,
    username VARCHAR(50),
    message TEXT,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
