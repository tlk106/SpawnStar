# To Do

## v0.1.0 
#### ETA 2026/02/28
- [X] Create Window
- [X] Generate random points using a Star Class
- [X] Add basic rendering
- [X] Add star colour and brightness (Short Lived Code for testing)
- [X] Get proper properties
    ### Given
    - [X] Star X
    - [X] Star Y
    - [X] Temperature
    - [X] Star Distance to observer
    - [X] Radius
    ### Need to be calculated
    - [X] Luminosity
    - [X] Absolute Magnitude (This is needed to calculate apparent)
    - [X] Apparent Magnitude (This is how the star looks at the specific distance)
    - [X] Mass (Needed for surface gravity)
    - [X] Star Surface Gravity (I need this for Luminosity class. Because of a misnomer I thought luminosity was for the luminosity class. This will be randomly generated based on the radius.)
- [X] Star Classification Function
    - [X] Spectral Type, based on temperature: (M, K, G, F, A, B, O), and a subclass (1 to 9)
    - [X] Luminosity Class, also gives life stage of the star: (I, II, III, ...)
    - [X] Function to combine the two
    - This should look like G2V, K5II or F3IV
- [ ] Render Stars
    - [ ] Colour Rendering based on star Spectral Type
    - [ ] Brightness Rendering based on Luminosity Class
    - [ ] Make it render a star like shape
- [ ] Polish

## v0.1.1 (Accuracy & Realism)
#### ETA 2025/03/05
- [ ] Make certian stars more common than others
    - [ ] More cooler stars
    - [ ] Make type V (main sequence) stars the most common and other types the least
- [ ] Polish 

## v0.2.0 (UI Update)
#### ETA 2025/03/14
- [ ] Show star properties on hover
- [ ] Refresh button
- [ ] Polish
- [ ] Comment out anything printed with ```SDL_LOG```


## v0.3.0 (Star Drift)
#### ETA 2025/04/06
- [ ] Display year
- [ ] Pause and Play buttons
- [ ] Change year when played
- [ ] Add rate of change properties for each star
    - [ ] Star X
    - [ ] Star Y
    - [ ] Star Distance to observer
- [ ] Add reversing
- [ ] Polish