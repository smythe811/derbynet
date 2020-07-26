<?php

function make_scene($sceneid, $name, $main, $aux1, $aux2) {
  $result = array();
  $result[] = 'INSERT INTO Scenes(sceneid, name, sortorder)'
                  .' VALUES('.$sceneid.', \''.$name.'\', '.$sceneid.')';
  $result[] = 'INSERT INTO SceneKiosk(sceneid, kiosk_name, page)'
          .' VALUES('.$sceneid.', \'Main\', \''.$main.'\')';
  if (!empty($aux1)) {
    $result[] = 'INSERT INTO SceneKiosk(sceneid, kiosk_name, page)'
            .' VALUES('.$sceneid.', \'Aux1\', \''.$aux1.'\')';
  }
  if (!empty($aux2)) {
    $result[] = 'INSERT INTO SceneKiosk(sceneid, kiosk_name, page)'
            .' VALUES('.$sceneid.', \'Aux2\', \''.$aux2.'\')';
  }
  return $result;
}

return array_merge(
array(

"DROP TABLE IF EXISTS SceneKiosk",

"DROP TABLE IF EXISTS Scenes",
"CREATE TABLE Scenes ("
." sceneid INTEGER PRIMARY KEY,"
." name VARCHAR(200),"
." sortorder INTEGER"
.")",


"CREATE TABLE SceneKiosk ("
." sceneid INTEGER,"
." kiosk_name VARCHAR(200),"
." page VARCHAR(200)"
.")",

"CREATE INDEX IF NOT EXISTS SceneKiosk_primary ON SceneKiosk(sceneid, kiosk_name)",
  ),

// Possible parameters for pages:
// kiosks/please-check-in.kiosk#{"classids":[1,2,3]}
// kiosks/award-presentations.kiosk#{"confetti":false}
// kiosks/slideshow.kiosk#{"title":"","classids":[1,2,4,5]}

make_scene(1, 'Welcome', 'kiosks/welcome.kiosk', '', ''),

make_scene(2, 'Check-In', 'kiosks/slideshow.kiosk',
           'kiosks/please-check-in.kiosk', 'kiosks/welcome.kiosk'),

make_scene(3, 'Racing', 'kiosks/now-racing.kiosk',
           'kiosks/ondeck.kiosk', 'kiosks/results-by-racer.kiosk'),

make_scene(4, 'Awards', 'kiosks/award-presentations.kiosk', '', ''),

make_scene(5, 'Wrap-Up', 'kiosks/standings.kiosk',
           'kiosks/derbynet.kiosk', 'local/kiosks/feedback.kiosk'),

);
?>