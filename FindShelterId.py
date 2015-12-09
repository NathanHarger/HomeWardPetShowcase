import requests
import json
apiKey = raw_input('Enter Api Key ')
zipCode = raw_input('Enter Shelter Zip Code ')
shelterSearch = raw_input('Enter Shelter Search Term ')

r = requests.get('http://api.petfinder.com/shelter.find?key='+apiKey+ '&location=' +zipCode +'&name=' + shelterSearch +'&format=json');
jsonData = json.loads(r.content);
jsonArray = jsonData['petfinder']['shelters']['shelter']

for e in jsonArray:
    print
    for k,v in e.items():
     if(k =='name' or k=='id' or k=='state'):
        value = v['$t']
        print k + ':',value



