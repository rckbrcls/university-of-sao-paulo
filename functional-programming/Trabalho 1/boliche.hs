import Data.List.Split (chunksOf)

type Frame = (Int, Int)

isStrike :: Frame -> Bool
isStrike (x, _) = x == 10

isSpare :: Frame -> Bool
isSpare (x, y) = x + y == 10 && x /= 10

calculateScore :: [Frame] -> Int
calculateScore frames = go 1 frames
  where
    go _ [] = 0
    go _ [_] = 0
    go _ [_, _] = 0
    go frameIndex ((x, y):rest@(next@(a, b):following@(c, _)):frames)
      | isStrike (x, y) = (10 + bonus next following) + go (frameIndex + 1) (next:following:frames)
      | isSpare (x, y) = (10 + bonus next) + go (frameIndex + 1) (following:frames)
      | otherwise = (x + y) + go (frameIndex + 1) frames
      where
        bonus (a, b) (_, _) = a + b
        bonus (a, b) _ = a

formatFrames :: [Frame] -> String
formatFrames frames = concatMap formatFrame frames
  where
    formatFrame (x, y)
      | x == 10 = "X "
      | x + y == 10 = show x ++ " / "
      | otherwise = show x ++ " " ++ show y ++ " "

parseInput :: String -> [Frame]
parseInput input = map parseFrame (chunksOf 2 (words input))
  where
    parseFrame [x, y] = (read x, read y)
    parseFrame [x] = (read x, 0)

main :: IO ()
main = do
  putStrLn "Digite a sequência de pinos derrubados:"
  input <- getLine
  let frames = parseInput input
      score = calculateScore frames
      formattedFrames = formatFrames frames
  putStrLn $ "Sequência de pinos derrubados: " ++ formattedFrames
  putStrLn $ "Pontuação final: " ++ show score
