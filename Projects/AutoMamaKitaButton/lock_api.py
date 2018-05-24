from flask import Flask
from flask_cors import  CORS
import subprocess
app = Flask(__name__)
cors=CORS(app)

@app.route("/")
def data():
    return subprocess.run("i3lock")

app.run(host="0.0.0.0")
