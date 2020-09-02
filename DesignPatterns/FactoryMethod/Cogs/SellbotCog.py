# Project imports
from Cogs.Cog import Cog
from Cogs.CogEnums import CogType

class SellbotCog(Cog):
  @property
  def cogType(self) -> CogType:
    return CogType.SELLBOT

