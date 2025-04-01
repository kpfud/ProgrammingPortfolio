from flask import Flask, render_template, request, redirect, jsonify
import os

app = Flask(__name__)

ACCESS_TOKEN = 'church_access_token_here'
dbx = dropbox.Dropbox(ACCESS_TOKEN)

FILE_PATH= 'PrCnt.txt'

#Function to read the current prayer count
def get_prayer_count():
    try:
        with open(FILE_PATH, 'r') as f:
            return int(f.read().strip())
    except (FileNotFoundError, ValueError):
        return 0 #default to 0 if the file doesn't exist
    
#Function to update the prayer count
def update_prayer_count(count):
    with open(FILE_PATH, 'w') as f:
        f.write(str(count))

@app.route('/prayer_counter')
def home():
    #get the current count from the file
    current_count = get_prayer_count()
    return render_template('prayer_counter.html', prayer_count=current_count, new_count=current_count)

@app.route('/update', methods=['POST'])
def update_count():
    data = request.get_json()
    try:
        new_count = data.get('new_count', 0)
        update_prayer_count(new_count)
        return jsonify(success=True)
    except ValueError:
        return jsonify(success=False, error="Invalid number"), 400


if __name__ == '__main__':
    app.run(debug=True)