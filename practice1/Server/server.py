import socketserver
import logging
from datetime import datetime

# --- Logging setup ---
logging.basicConfig(
    filename="kvserver.log",
    level=logging.INFO,
    format="%(asctime)s - %(message)s",
)

class KeyValueStore:
    def __init__(self):
        self.store = {}

    def put(self, key, value):
        if key in self.store:
            self.store[key] = value
            return "200 OK"
        else:
            self.store[key] = value
            return "201 CREATED"

    def get(self, key):
        return f"200 OK {self.store[key]}" if key in self.store else "404 NOT_FOUND"

    def delete(self, key):
        if key in self.store:
            del self.store[key]
            return "204 NO_CONTENT"
        return "404 NOT_FOUND"

    def stats(self):
        return f"200 OK {len(self.store)} keys stored"
    
class KeyValueTCPHandler(socketserver.StreamRequestHandler):
    protocol_version = "KV/1.0"  # version

    def parse_request(self, raw_request):
        """Parse and validate the request once here."""
        try:
            parts = raw_request.strip().split(" ", 2)
            if len(parts) < 2:
                return None, "400 BAD_REQUEST"

            version, command = parts[0], parts[1]
            if version != self.protocol_version:
                return None, "426 UPGRADE_REQUIRED"

            # Key and value (if present)
            key = None
            value = None
            if command in ["PUT", "GET", "DEL"]:
                if len(parts) < 3:
                    return None, "400 BAD_REQUEST"
                key_value = parts[2].split(" ", 1)
                key = key_value[0]
                if command == "PUT" and len(key_value) > 1:
                    value = key_value[1]

            return (command, key, value), None
        except Exception:
            return None, "500 SERVER_ERROR"
        
    def handle(self):
        store = self.server.store
        while True:
            data = self.rfile.readline().decode("utf-8").strip()
            if not data:
                break

            request, error = self.parse_request(data)
            if error:
                self.wfile.write((error + "\n").encode("utf-8"))
                continue

            command, key, value = request

            if command == "PUT":
                response = store.put(key, value)
            elif command == "GET":
                response = store.get(key)
            elif command == "DEL":
                response = store.delete(key)
            elif command == "STATS":
                response = store.stats()
            elif command == "QUIT":
                response = "200 OK Bye"
                self.wfile.write((response + "\n").encode("utf-8"))
                logging.info(f"Request: {data} | Response: {response}")
                break
            else:
                response = "400 BAD_REQUEST"

            # Send response
            self.wfile.write((response + "\n").encode("utf-8"))
            
            # Log request/response with timastamp
            logging.info(f"Request: {data} | Response: {response}")
            
class KeyValueServer(socketserver.TCPServer):
    def __init__(self, server_address, handler_class=KeyValueTCPHandler):
        super().__init__(server_address, handler_class)
        self.store = KeyValueStore()

if __name__ == "__main__":
    HOST, PORT = "127.0.0.1", 5050
    with KeyValueServer((HOST, PORT), KeyValueTCPHandler) as server:
        print(f"Serving on {HOST}:{PORT}")
        server.serve_forever()