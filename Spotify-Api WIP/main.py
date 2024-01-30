import os
from dotenv import load_dotenv
import base64  
from requests import post, get
import json


load_dotenv()

client_id = os.getenv("CLIENT_ID")
client_secret = os.getenv("CLIENT_SECRET")

def get_token():
    
    auth_string = client_id + ":" + client_secret
    auth_bytes  = auth_string.encode ("utf-8")
    auth_base64 = str(base64.b64encode(auth_bytes), "utf-8")

    url = "https://accounts.spotify.com/api/token"
    headers ={
        "Authorization": "Basic " + auth_base64,
        "Content-Type": "application/x-www-form-urlencoded"
    }
    #converting json data to string to be able to access it properly#
    data = {"grant_type": "client_credentials"}
    result = post (url, headers=headers, data=data)
    json_result = json.loads(result.content)

    if "access_token" in json_result:
        token = json_result["access_token"]
        return token
    else:
        print("Error in API response:", json_result)
        return None

def get_auth_header(token):
    return{"Authorization" : "Bearer " + token}

#Function that searches for an artist#

def search_for_artist(token, artist_name):
    url = "https://api.spotify.com/v1/search"
    headers = get_auth_header(token)
    query = f"?q={artist_name}&type=artist&limit=1"
    query_url = url + query 
    result = get(query_url,headers=headers)
    json_result = json.loads(result.content)["artists"]["items"]

    if len (json_result) == 0:
       # print(f"No playlist with the name '{playlist_name}' exists for the artist '{artist_name}'.")
        return None 
    return json_result[0]['id']


def get_songs_by_artist(token, artist_id):
    url = f"https://api.spotify.com/v1/artists/{artist_id}/top-tracks?country=US"
    headers = get_auth_header(token)
    result = get(url, headers=headers)
    json_result = json.loads(result.content)
    
    #JSON response when there is no tracks
    if "tracks" in json_result:
        return json_result["tracks"][:10]
    else:
        print("Error in the JSON response, tracks not found")
        return None
#Functions for getting artist playlists#

def get_albums_by_artist(token,artist_id):
    url = f"https://api.spotify.com/v1/artists/{artist_id}/albums?limit=10"
    headers = get_auth_header(token)
    result = get(url, headers=headers)
    json_result = json.loads(result.content)
    
     #JSON response when there is no tracks
    if "items" in json_result:
        return json_result["items"]
    else:
        print("Error in the JSON response, tracks not found")
        return None

token = get_token()
print (token)

artist_name=("Coldplay")
artist_id = search_for_artist(token, artist_name)

if artist_id:

    artist_id = search_for_artist(token, artist_name) #playlist_name))
    songs = get_songs_by_artist(token, artist_id)
    Albums = get_albums_by_artist(token, artist_id)


    print("\nSongs:")
    if songs:
        for idx, song in enumerate(songs):
            print(f"{idx + 1}. {song['name'].encode('utf-8').decode('cp1252', 'ignore')}")
    else:
        print("No songs found")

    print("\nAlbums:")
    if Albums:
        for idx, album in enumerate(Albums):
            print(f"{idx + 1}. {album['name']}")
    else:
            print("No albums found")
else:
            print(f"No artist found with the name '{artist_name}'.")

