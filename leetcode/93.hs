validSegment s =
  let n = read s :: Int in
  n >= 0 && n <= 255

restoreIpAddress :: String -> Int -> [String]
restoreIpAddress s n =
  if n < 1 then
    [[]]
  else
    case s of
    [] -> [[]]
    _  -> 
      concatMap (\h -> map (\t -> h ++ "." ++ t) (restoreIpAddress (drop (length h) s) (n-1))) (filter validSegment (map (\n -> take n s) [1..3]))