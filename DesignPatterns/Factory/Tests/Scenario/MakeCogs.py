"""Test factory creation of cogs.
"""

# Project imports
from Cogs.CogEnums import SellbotCogType
from Cogs.CogFactory import makeCog

# Make various cog types to test the Factory design pattern
cc = makeCog(SellbotCogType.COLD_CALLER)
print(cc.name, cc.cogType, cc.examine, sep=',')

t = makeCog(SellbotCogType.TELEMARKETER)
print(t.name, t.cogType, t.examine, sep=',')

